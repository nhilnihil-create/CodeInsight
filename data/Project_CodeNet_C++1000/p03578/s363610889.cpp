#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    map<int,int> a;
    int n, m;
    cin >> n;
    int d, t;
    for(int i=0; i<n; i++){
        cin >> d;
        a[d]++;
    }
    cin >> m;
    if(n<m){
        puts("NO");
        return 0;
    }
    for(int i=0; i<m; i++){
        cin >> t;
        if(a[t]) a[t]--;
        else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}