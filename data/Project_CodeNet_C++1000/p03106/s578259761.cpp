#include <bits/stdc++.h>
using namespace std;
     
#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    int A,B,K,buf;
    vector<int> ans;
    cin >> A >> B >> K;
    int a=min(A,B);
    if(A==1){
        cout << 1 << endl;
        return 0;
    }
    for(int i=1;i<=a;i++){
        if(A%i==0&&B%i==0){
            ans.push_back(i);
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans.at(K-1) << endl;
}