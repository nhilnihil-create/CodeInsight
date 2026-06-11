#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define BIT(n) (1LL<<(n))
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;
int main(void){
    // Your code here!
    /*
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    vector<int> v;
    v.push_back(a[0]);
    v.push_back(a[1]);
    v.push_back(a[2]);
    sort(ALL(v));
    
    int count;
    int max;
    int remain = (v[2]-v[1])+(v[2]-v[0]);
    if (remain%2==1){
        max = v[2]+1;
        count = 1;
        v[0] += 1;
    }
    else{
        max = v[2];
        count =0;
    }
    count += ((max-v[1])+(max-v[0]))/2;
    */
    int N;
    cin >> N;
    
    REP(i,N){
        ll a,b;
        cin >> a >> b;
        if (a < b){
            ll c = b;
            b = a;
            a = c;
        }
        
        ll product = a*b;
        ll sqrtpro = sqrt(product);
        int adj =0;
        
        if (sqrtpro*(sqrtpro+1) < product){
            if (sqrtpro+1 == a && sqrtpro == b){
                
                //cout << "a" << endl;
            }
            else {
                adj -=1;
                //cout << "b" << endl;
            }
            
        }
        else {
            if (sqrtpro==a && sqrtpro ==b){
                adj -=2;
                
                //cout << "t" << endl;
            }
            else if (sqrtpro*sqrtpro==product){
                adj -=3;
                //cout << "c" << endl;
            }
            else{
                adj-=2;
                //cout << "d" << endl;
            
            }
            
        }
        
        
    cout << sqrtpro*2+adj << endl;
    }
}
    
    
