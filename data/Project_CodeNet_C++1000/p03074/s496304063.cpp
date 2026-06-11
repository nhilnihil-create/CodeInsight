#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a;
    int cnt = 1;
    bool flag;
    if(s[0]=='1') flag = true;
    else flag = false;

    rep(i,s.size()-1){
        if(flag){
            if(s[i+1]=='0'){
                flag = false;
                a.push_back(cnt);
                cnt = 1;
            }else cnt++;
        }else{
            if(s[i+1]=='1'){
                flag = true;
                a.push_back(cnt);
                cnt = 1;
            }else cnt++;
        }
    }
    a.push_back(cnt);
    if(s[n-1]=='0')a.push_back(0);
    int cnt0 = 0;
    int cnt1 = 0;
    if(s[0]=='0'){
        cnt1 = a.size()/2;
        cnt0 = cnt1+a.size()%2;
    }else{
        cnt0 = a.size()/2;
        cnt1 = cnt0 + a.size()%2;
    }

    int sum = 0;
    int ans = 0;
    if(k>=cnt0) {
        cout << n << endl;
        return 0;
    };
    
    if(s[0] =='0'){
        int ind = 0;
        rep(i,2*k) sum += a[i];
        ans = max(ans,sum);
        if(a.size()>2*k+1) sum += (a[2*k]+a[2*k+1]);
        else sum += a[2*k];
        sum -= (a[ind]);
        ans = max(ans,sum);
        ind++;
        while(ind+2*k+2<=a.size()-1){
            sum += (a[ind+2*k+1]+a[ind+2*k+2]);
            sum -= (a[ind]+a[ind+1]);
            ans = max(ans,sum);
            ind += 2;
        }
    }else{
        int ind = 0;
        rep(i,2*k+1) sum += a[i];
        ans = max(ans,sum);
        while(ind+2*k+2<=a.size()-1){
            sum += a[ind+2*k+1] + a[ind+2*k+2];
            sum -= (a[ind]+a[ind+1]);
            ans = max(ans,sum);
            ind += 2;
        }
    }
    //rep(i,a.size()) cout << a[i] << endl;
    cout << ans  << endl;
}