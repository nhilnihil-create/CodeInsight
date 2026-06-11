#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    string s;
    cin>>s;
    string S=s;
    int z=s.size();
    rep(i,z){
        for(int k=0;k<z-i;k++){
            s.erase(i,k);
            if(s=="keyence"){
                cout<<"YES"<<endl;
                return 0;
            }
            s=S;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
