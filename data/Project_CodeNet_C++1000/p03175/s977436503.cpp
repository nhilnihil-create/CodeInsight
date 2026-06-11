#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int, int>
#define M 1000000007

// pi.first is the no. of ways if root is white
// pi.second is the no. of ways if root is black
pi dfs(vector<int> edges[], int sv, int parent){

    // We have 2 options: make the current 'sv' as black or white
    // If we make it black, then all of its children must be white
    // If we make it white, then either all children are white or
    // some children are black

    // Take example of tree
    //           1
    //         / | \
    //        2  3  4
    // B1 is the no. of ways if the root node is to be black
    // W1 is the no. of ways if the root node is to be white
    // B1 = W2*W3*W4
    // W1 = W2*W3*W4 + B2*W3*W4 + W2*B3*W4 + W2*W3*B4 + B2*B3*W4 + B2*W3*B4 +
    //      W2*B3*B4 + B2*B3*B4

    // Suppose we are at the third child (4)
    // We already have these values
    // B1 = W2*W3
    // W1 = W2*W3 + B2*W3 + W2*B3 + B2*B3
    // Now we get B4 and W4 from the recursion for the third child
    // Then B1 = B1*W4
    //      W1 = W1*(W4 + B4)
    // (If the current node is to be black, then child must be white)
    // (If the current node is to be white, then child can be either black or white)
    // On expanding, we get the above values

    ll w = 1, b = 1;

    for(int child: edges[sv]){
        if(child == parent)
            continue;
        pi childAns = dfs(edges, child, sv);
        ll childW = childAns.first, childB = childAns.second;
        b = (b*childW)%M;
        w = (w*((childW + childB)%M))%M;
    }

    pi ans = {w, b};
    return ans;
}

int independentSet(vector<int> edges[], int n){

    pi rootAns = dfs(edges, 0, -1);
    ll ans = (rootAns.first + rootAns.second)%M;
    return ans;
}

int main()
{
 int n;
 cin>>n;
 vector<int> edges[n];
 int u, v;
 for(int i=0; i<n-1; i++){
    cin>>u>>v;
    edges[u-1].push_back(v-1);
    edges[v-1].push_back(u-1);
 }
 int ans = independentSet(edges, n);
 cout<<ans;
 return 0;
}
