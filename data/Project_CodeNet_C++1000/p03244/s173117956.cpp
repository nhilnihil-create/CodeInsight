#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, ans;
    cin >> n;
    vector<int>a(n);
    vector<pair<int,int>> o(100001),e(100001);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        if(i%2==0){
            e[a[i]].first++;
            e[a[i]].second = a[i];
        }else{
            o[a[i]].first++;
            o[a[i]].second = a[i];
        }
    }
    sort(e.rbegin(),e.rend());
    sort(o.rbegin(),o.rend());
    if(e[0].second != o[0].second){
        ans = n - e[0].first - o[0].first;
    }else{
        int t = max(e[0].first+o[1].first, e[1].first+o[0].first);
        ans = n - t;
    }
    printf("%d\n",ans);
    return 0;
}