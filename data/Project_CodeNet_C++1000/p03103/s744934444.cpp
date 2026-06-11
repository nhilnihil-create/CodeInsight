#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<long long,long long>>ab(n);
    for(int i=0; i<n; i++){
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(),ab.end());
    long long ans = 0, tmp=m;
    for(int i=0; i<n; i++){
        if(ab[i].second>=tmp){
            ans += ab[i].first * tmp;
            break;
        }else{
            ans += ab[i].second * ab[i].first;
            tmp -= ab[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}