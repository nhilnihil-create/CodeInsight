#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF=pow(10,9);

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> plus(1,0),minus(1,0);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x<0) minus.push_back(-x);
        else plus.push_back(x);
    }
    sort(minus.begin(), minus.end());
    int ans=INF;
    for (int i=0; i<=k; i++){
        if(i<plus.size() && k-i<minus.size()){
            int t;
            t =  plus.at(i)+minus.at(k-i) +min(plus.at(i), minus.at(k-i));
            ans=min(ans, t);
        }
    }
    cout << ans << endl;
}
