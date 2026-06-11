#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(m);
    vector<int> y(m);
    vector<vector<int>> all(n);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a--;
        p.at(i) = a;
        y.at(i) = b;
        all.at(a).push_back(b);
    }
    for(int i=0; i<n; i++){
        sort(all.at(i).begin(), all.at(i).end());
    }
    for(int i=0; i<m; i++){
        int a,b;
        a = p.at(i);
        b = y.at(i);
        int s = all.at(a).size();
        int l=-1; int r= s;
        while(l+1 < r){
            int mid = (l+r)/2;
            if(all.at(a).at(mid) >= b){
                r = mid;
            }
            else l = mid;
        }
        printf("%06d%06d\n", a+1, r+1);
    }
}