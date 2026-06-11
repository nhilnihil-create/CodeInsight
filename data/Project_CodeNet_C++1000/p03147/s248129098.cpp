 #include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int first(vector<int> h){
    for(int i=0;i<h.size();i++){
        if(h[i]!=0){
            return i;
        }
    }
    return -1;
}
int last(vector<int> h,int left){
    for(int i=left;i<h.size();i++){
        if(h[i]==0) return i-1;
    }
    return h.size()-1;
}
void water(vector<int> &h,int left,int right,int &ans){
    for(int i=left;i<=right;i++){
        h[i]--;
    }
    ans++;
}
bool allzero(vector<int> h){
    for(int i=0;i<h.size();i++){
        if(h[i]>0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    int ans=0;
    while(!allzero(h)){
        int left=first(h);
        int right=last(h,left);
        water(h,left,right,ans);
    }
    cout << ans << endl;
}