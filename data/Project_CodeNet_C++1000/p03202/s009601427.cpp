#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};




int main(){
    int n;cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto f = [&](int k){
        map<int,int> ma;
        int bf=0;
        for (int i = 0; i < n; i++) {
            if(a[i] <= bf){
                int t = a[i];
                ma[t]++;
                ma.erase(++ma.find(t),ma.end());
                while(ma[t] >= k){
                    ma[t]=0;
                    ma[t-1]++;
                    t--;
                    if(t<=0||k==1) return false;
                }
            }
            bf=a[i];
        }
        return true;
    };
    int l = 0, r = INF;
    while(abs(r - l) > 1){
        int m =  l + (r - l) / 2;
        if(f(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}
