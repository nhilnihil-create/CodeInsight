#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
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
void output(vector<int> s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            cout << " ";
        cout << s[i]; //<<endl;
    }
    cout << endl;
}

int MOD = pow(10, 9) + 7;

//各要素で最低操作回数を数える
pair<int,int> count(vector<int> a,vector<int> b){
    int n=a.size();
    int a_cnt=0,b_cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            b_cnt+=(a[i]-b[i]);
        }
        if(a[i]<b[i]){
            if((b[i]-a[i])%2==0){
                a_cnt+=(b[i]-a[i])/2;
            }else{
                a_cnt+=(b[i]-a[i])/2 +1;
            }
        }
    }

    return make_pair(a_cnt,b_cnt);
}

signed main(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    //和を計算しておく
    int sum_a=accumulate(all(a),0LL);
    int sum_b=accumulate(all(b),0LL);

    //aの和の方が大きいと、確実に無理
    if(sum_a>sum_b) cout<<"No"<<endl;
    else{
        //aの最低操作回数とbの最低操作回数を得る。これが操作回数を超えなければ良い。
        pair<int,int> cnt=count(a,b);
        if(cnt.first>sum_b-sum_a) cout<<"No"<<endl;
        else if(cnt.second>sum_b-sum_a) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}