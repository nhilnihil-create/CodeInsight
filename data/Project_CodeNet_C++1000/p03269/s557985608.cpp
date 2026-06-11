#include<bits/stdc++.h>
using namespace std;
int main(){
    int L;
    cin >> L;
    vector<tuple<int,int,int>> path;
    int i=1;
    while(L>1){
        if(L%2)path.push_back(make_tuple(i,100,L-1));
        path.push_back(make_tuple(i,i+1,L/2));
        path.push_back(make_tuple(i,i+1,0));
        i++;
        L/=2;
    }
    cout << i << " " << path.size() << endl;
    for(auto t:path){
        cout << get<0>(t) << " " << min(i,get<1>(t)) << " " << get<2>(t) << endl;
    }
}