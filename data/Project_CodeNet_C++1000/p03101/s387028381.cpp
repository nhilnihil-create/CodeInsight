#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int H,W,h,w;
    cin>>H>>W;
    cin>>h>>w;
    cout<<H*W-h*W-w*H+h*w<<endl;
}