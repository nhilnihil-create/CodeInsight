/*
Auther : Snickeen.
Date : 201909227 
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN  = 2e5+7;

int n, ans;
vector<vector<int> > a(33), b(33);

void input(vector<vector<int> >& in){
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        for(int j = 0; j < 30; ++j){
            int k = (1 << (j + 1)) - 1;
            in[j].push_back(m & k);
        }
    }
    for(int i = 0; i < 30; ++i) {
        sort(in[i].begin(), in[i].end());
        //for(auto x :in[i]) cout<<x<<" "; cout<<endl;
    }
}

int main()
{
    cin >> n;
    input(a); input(b);
    for(int i = 0; i < 30; ++i){
        int l1 = 0, r2 = 0, l3 = 0, r4 = 0;
        long long T=1<<i, T2=T<<1, T3=T+T2, T4=T2<<1;
        int res = 0;
        for(int j = n-1; j >= 0; --j){
            for(;l1 < n; ++l1) if(a[i][j]+b[i][l1] >= T) break;
            for(;r2 < n; ++r2) if(a[i][j]+b[i][r2] >= T2)break;
            for(;l3 < n; ++l3) if(a[i][j]+b[i][l3] >= T3)break;
            for(;r4 < n; ++r4) if(a[i][j]+b[i][r4] >= T4)break;
            int cnt = (r2 - l1) + (r4 - l3);
            res ^= cnt & 1;
            //cout<<i<<" "<<j<<" "<<l1<<" "<<r2<<" "<<l3<<" "<<r4<<" "<<cnt<<endl;
        }
        ans |= res << i;
    }
    cout << ans << endl;
    return 0;
}


/*

arc92b D - Two Sequences


*/
