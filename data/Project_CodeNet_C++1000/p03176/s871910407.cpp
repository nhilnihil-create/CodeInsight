#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,CApiTaL_N) for(int i=0; i<CApiTaL_N; i++)
#define Fo(i,k,CApiTaL_N) for(int i=k; i<CApiTaL_N; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t;
int n;
const int mxN=2e5;
vl h(mxN+1),b(mxN+1),dp(mxN+1);

vl segmentTree;
vl arr(mxN+1);

void initSegmentTree() {
    int length = 2 * pow(2.0, ceil(log((double) mxN+1 ) / log(2.0)));
    segmentTree.clear();
    segmentTree.resize(length, 0);
}

void buildHelper(int node, int start, int end){
    if(start==end){
        segmentTree[node] = start;
        return;
    }

    int mid = (start+end)/2;
    int lIndex = node << 1, rIndex = lIndex | 1;

    buildHelper(lIndex, start, mid);
    buildHelper(rIndex, mid+1, end);
    int lContent = segmentTree[lIndex], rContent = segmentTree[rIndex];

    segmentTree[node] = (arr[lContent]>=arr[rContent]) ? lContent : rContent;
}

int queryHelper(int node, int start, int end, int i, int j){
    if(i>j)return 0;
    if(i > end || j < start)return -1;
    if(start >= i && end <= j)return segmentTree[node];

    int mid = (start+end)/2;
    int lIndex = node<<1, rindex = lIndex | 1;

    int lContent = queryHelper(lIndex, start, mid, i, j);
    int rContent = queryHelper(rindex, mid+1, end, i, j);
    
    if(lContent==-1)return rContent;
    if(rContent==-1)return lContent;
    return (arr[lContent] >= arr[rContent]) ? lContent : rContent;
}

void updatePoint(int node, int start, int end, int qIndex){
    if( qIndex < start || qIndex > end || start > end ) return;
    if(start==end){
        segmentTree[node] = start;
        return;
    }

    int mid = (start+end)/2;
    int lIndex = node << 1, rindex = lIndex | 1;

    updatePoint(lIndex, start, mid, qIndex);
    updatePoint(rindex, mid+1, end, qIndex);

    int lContent = segmentTree[lIndex], rContent = segmentTree[rindex];
    segmentTree[node] = (arr[lContent]>=arr[rContent]) ? lContent : rContent;
}

void test_case(){
    cin>>n;
    fo(i,n)cin>>h[i];
    fo(i,n)cin>>b[i];
    dp[0]=b[0];
    initSegmentTree();
    arr[h[0]]=dp[0];
    // cout<<h[0]<<" s"<<arr[1]<<endl;
    buildHelper(1,1,n);
    // fo(i,n+1)cout<<arr[i]<<" ";
    // cout<<endl;
    // fo(i,n+1)cout<<segmentTree[i]<<" ";
    // cout<<endl;
    Fo(i,1,n){
        // cout<<i<<" "<<h[i]<<" "<<queryHelper(1,1,n,1,h[i]-1)<<endl;
        ll mb=arr[queryHelper(1,1,n,1,h[i]-1)];
        // fo(j,i){
        //     if(h[j]<h[i]){
        //         // cout<<i<<" "<<dp[j]<<endl;
        //         mb=max(mb,dp[j]);
        //     }
        // }
        dp[i]=mb+b[i];
        // cout<<i<<" "<<mb<<" "<<dp[i]<<endl;
        arr[h[i]]=dp[i];
        updatePoint(1,1,n,h[i]);
    }
    ll ans=0;
    fo(i,n){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }
    
    return 0;
}