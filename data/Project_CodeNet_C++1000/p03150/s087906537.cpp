#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n-1){
        for(int j = 1;j<n;j++){
            string t = s.substr(0,i)+s.substr(j,n-1-j+1);
            if(t=="keyence"){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}