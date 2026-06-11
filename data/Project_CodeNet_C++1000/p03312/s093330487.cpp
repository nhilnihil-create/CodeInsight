#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()


using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;


int main(){
    int N; cin >> N;
    vector<ll> A(N), sum(N+1, 0);
    for(int i=0; i<N; i++){
        cin >> A[i];
        sum[i+1]=sum[i]+A[i];
    }
    ll res=LINF;
    int left_low=1, right_low=2;
    for(int i=2; i<=N-2; i++){
        while(sum[left_low] <= sum[i]-sum[left_low] && left_low < i){
            left_low++;
        }
        ll P1=sum[left_low], Q1=sum[i]-sum[left_low];
        ll P2=sum[left_low-1], Q2=sum[i]-sum[left_low-1];
        ll left_min=min(P1, Q1), left_max=max(P1, Q1);
        if(abs(P2-Q2) < abs(P1-Q1)) left_min=min(P2, Q2), left_max=max(P2, Q2);

        while(sum[right_low]-sum[i] <= sum[N]-sum[right_low] && right_low < N){
            right_low++;
        }
        if(right_low <= i) right_low=i+1;
        ll R1=sum[right_low]-sum[i], S1=sum[N]-sum[right_low];
        ll R2=sum[right_low-1]-sum[i], S2=sum[N]-sum[right_low-1];
        ll right_min=min(R1, S1), right_max=max(R1, S1);
        if(abs(R2-S2) < abs(R1-S1)) right_min=min(R2, S2), right_max=max(R2, S2);

        ll tmp=max(left_max, right_max)-min(left_min, right_min);
        res=min(res, tmp);
    }
    cout << res << endl;
    return 0;
}