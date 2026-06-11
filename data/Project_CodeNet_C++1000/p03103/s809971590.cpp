#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin >> n >> m;

    vector<tuple<long long int,long long int>> drink(n);
    int a,b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        drink.at(i)=make_tuple(a,b);
        //cout << get<0>(drink.at(i)) << ' ' << get<1>(drink.at(i)) << endl;
    }
    sort(drink.begin(), drink.end());

    int i=0;
    long long int count=m;
    long long int price=0;
    while(1){
        if(get<1>(drink.at(i))<count){
            price+=get<0>(drink.at(i))*get<1>(drink.at(i));
            count-=get<1>(drink.at(i));
            i++;
        }
        else{
            price+=get<0>(drink.at(i))*count;
            break;
        }
    }
    cout << price << endl;
}