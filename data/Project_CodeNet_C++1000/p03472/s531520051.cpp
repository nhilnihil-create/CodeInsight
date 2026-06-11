#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}

int MOD = pow(10, 9) + 7;

int kaijou(int n){
    if(n==0) return 1;
    else{
        return ((n%MOD)*(kaijou(n-1)%MOD))%MOD;
    }
}

bool ispow(int n){
    int rn=sqrt(n);
    if(rn*rn==n) return true;
    else return false;
}

signed main() {
    int n,h; cin>>n>>h;
    int ans=0;

    vector<pair<int,int>> ab(n),ba(n);
    vector<int> b(n);

    for(int i=0;i<n;i++){
        int ai,bi;cin>>ai>>bi;
        ab[i]=make_pair(ai,bi);
        b[i]=bi;
    }

    sort(all(ab));
    sort(all(b));

    //cout<<1<<endl;

    int a_max=ab.at(n-1).first;
    int throw_index=distance(b.begin(),upper_bound(all(b),a_max));//投げたほうが効率が良いポイント

    //cout<<throw_index<<endl;

    for(int i=n-1;i>=throw_index;i--){
        h-=b.at(i);
        ans++;
        if(h<=0){
            cout<<ans<<endl;
            return 0;
        }
    }

    int a_cnt=h/a_max;
    if((h%a_max)!=0) a_cnt++;

    ans+=a_cnt;

    cout<<ans<<endl;
}
