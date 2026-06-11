#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

typedef long long ll;
using namespace std;



bool isPrime(ll n){
    if(n < 2){
        return 0;
    }
    if(n%2 == 0){
        return n==2;
    }
    for(ll i=3;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

string toBinary(ll x){
    string s = "";
    while(x > 0){
        if(x%2) s += "1";
        else s += "0";
        x /= 2;
    }
    string h = "";
    for(int i=s.size();i<31;i++){
        h += "0";
    }
    reverse(s.begin(),s.end());
    //cout<<"x "<<x<<" "<<(h+s)<<endl;
    return (h+s);
}

ll toInt(string s){
    int h =0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] ==  '1') h += pow(2,i);
    }
    return h;
}
vector<ll> getDivisors(ll n)
{
    vector<ll> v;
    v.push_back(1);
    ll i = 2;
    ll k = sqrt(n)+1;
    while(i <= k)
    {

        if(n%i==0) {
         //   cout<<"i "<<i<<" n/i "<<n/i<<endl;
            v.push_back(i);
            if (i != (n / i)) {
                v.push_back(n/i);
            }
        }

        i++;
    }
    return v;
}
struct node {
    int val;
    node* next;
};
vector<string> vs;
void generate(int i,int n,int r,int num,string s){
    if(i == n){
        if(num == r) vs.push_back(s);
        return;
    }
    generate(i+1,n,r,num+1,s+"1");
    generate(i+1,n,r,num,s+"0");
}

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}

bool isValid(int i,int j,int n,int m,vector<string> &v ,vector<vector<bool>> &vis){
    return i>=0&&i<n&&j>=0&&j<m&&!vis[i][j]&&v[i][j] == '.';
}

int di[4] = {0,0,1,-1};
int dj[4] = {-1,1,0,0};

vector<pair<int,int>> solve(int i,int j,int n,int m,vector<string> &v,vector<vector<bool>> &vis){
    vector<pair<int,int>> vv;
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]= 1;
    while (!q.empty()){
        pair<int,int> p = q.front();
        vv.push_back(p);
        q.pop();
        for(int k=0;k<4;k++){
            int ni = p.first+di[k];
            int nj = p.second+dj[k];
            if(isValid(ni,nj,n,m,v,vis)){
                vis[ni][nj]= 1;
                q.push({ni,nj});
            }
        }

    }
    return vv;
}
int main() {
    //freopen("test.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<ll> dp(n,10e9+10);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+2;j++){
            if(j < n){
                dp[j] = min(dp[j],dp[i] + (ll)abs(v[i]-v[j]));
               // if(i > 0) dp[i] += dp[i-1];
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
