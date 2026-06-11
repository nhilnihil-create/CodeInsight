#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e4 + 100;
int n;
long long x[maxn], y[maxn];
long long Abs(long long x) { return x < 0 ? -x : x;}
int main()
{
    cin>>n;
    int k = 0;
    for(int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
        long long ax = Abs(x[i]), ay = Abs(y[i]);
        //cout<<ax<<" "<<ay<<endl;
        if(i == 1) k = (ax + ay) & 1;
        else {
            if(k != ((ax + ay)&1)) { cout<<-1<<endl; return 0; }
        }
    }
    if(k == 1){
        cout<<31<<endl;
        for(int i = 30; i >= 0; i--) cout<<(1<<i)<<" "; cout<<endl;
    } else {
        cout<<32<<endl<<1<<" ";
        for(int i = 30; i >= 0; i--) cout<<(1<<i)<<" "; cout<<endl;
        for(int i = 1; i <= n; i++) x[i]--;
    }
    for(int i = 1; i <= n; i++){
        if(k == 0) cout<<"R";
        int nx = 0, ny = 0;
        for(int j = 30; j >= 0; j--){
            int d = (1<<j);
            if(Abs(nx-d-x[i]) + Abs(ny-y[i]) < d) cout<<"L", nx -= d;
            else if(Abs(nx+d-x[i]) + Abs(ny-y[i]) < d) cout<<"R", nx += d;
            else if(Abs(nx-x[i]) + Abs(ny-d-y[i]) < d) cout<<"D", ny -= d;
            else cout<<"U", ny += d;
        }
        //cout<<nx<<" "<<ny<<endl;
        cout<<endl;
    }
    return 0;
}
