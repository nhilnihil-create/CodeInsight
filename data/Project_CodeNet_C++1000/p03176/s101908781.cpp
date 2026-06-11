#include<bits/stdc++.h>
using namespace std;

void update(vector<long long int> &vec,long long int val,int pos){
    for(pos++;pos<vec.size();pos += (pos&(-pos)))
        vec[pos] = max(vec[pos], val);
}
long long int query(vector<long long int> &vec,int pos){
    long long int val = -1;
    for(pos++;pos;pos -= (pos&(-pos)))
         val = max(vec[pos],val);
    return val;
}
int main(){
    int n;
    cin >> n;
    int h[n+1], a[n+1];
    for(int i=0; i<n;i++)
        cin >> h[i];
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<long long int> ans(n+2,0);
    for(int i=0; i<n; i++){
        int x = h[i];
        long long int res = query(ans, x-1);
        update(ans, res+a[i], x);
    }
    cout << query(ans, n);
}