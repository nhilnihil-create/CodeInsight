
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int s;
    cin >> s;
    int ans=1;
    vector<int> num;

    while(true){
        for(int i=0; i<num.size(); i++){
            if(num[i]==s){
                cout << ans << endl;
                return 0;
            }
        }
        num.push_back(s);
        if(s%2==0){
            s /=2;
        }
        else if(s%2==1){
            s = 3*s+1;
        }
        ans ++;
    }
}