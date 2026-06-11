#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    map<int,int> a;
    int n, m;
    cin >> n;
    vector<int>d(n);
    for(int i=0; i<n; i++){
        cin >> d[i];
        a[d[i]]++;
    }
    cin >> m;
    if(n<m){
        puts("NO");
        return 0;
    }
    vector<int>t(m);
    for(int i=0; i<m; i++){
        cin >> t[i];
        if(a[t[i]]) a[t[i]]--;
        else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}