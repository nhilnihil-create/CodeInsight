#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    while (n!=0){
        int d;
        //cout << "N" << n;
        if(n>0){
            d=n%2;
            n=-(n/2);
        }
        else{
            d=(-n)%2;
            n=(-n+1)/2;
        }
        //cout << "d" << d << "n" << n << endl;
        ans.push_back(d);
    }
    reverse(ans.begin(), ans.end());
    if(ans.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans.at(i);
    }
    cout << endl;
}