#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;

int main() {
    int N;
    cin>>N;
    vector<int> D(N);
    for(int i=0;i<N;++i){
        cin>>D[i];
    }
    sort(D.begin(), D.end());
    int l=24, r=0;
    int ans = 24;
    for(int i=0;i<N;++i){
        if(i%2==0){
            if(ans > D[i] - r) ans = D[i] - r;
            r = D[i];
        }
        else{
            if(ans > l - (24-D[i])) ans = l - (24 - D[i]);
            l = 24 - D[i];
        }
        if(ans > l - r) ans = l - r;
    }
    cout<<ans<<endl;
}

