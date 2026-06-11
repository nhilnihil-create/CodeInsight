#include <iostream>
#include <map>
using namespace std;
int n, a[200000];
bool f(int x){
    int u=0;
    map<int, int> p;
    p[a[0]]=0;
    for(int i=1;i<n;i++){
        if(a[i] <= a[i-1]){
            u = a[i];
            while(u>0&&p[u]==x-1){
                u--;
            }
            if(u == 0)return false;
            p.erase(p.upper_bound(u), p.end());
            p[u]++;
        }
    }
    return true;
}
int main(void){
    int ng = 1, ok, m;
    cin >> n;
    bool p=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0&&a[i]<=a[i-1])p=false;
    }
    if(p){
        cout<<1<<endl;
        return 0;
    }
    ok = n;
    while(ng + 1 < ok){
        m = (ng + ok)/2;
        if(f(m)){
            ok = m;
        }else{
            ng = m;
        }
    }
    cout << ok << endl;
}
