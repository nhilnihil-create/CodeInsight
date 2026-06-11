#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>

typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e18;
const ll N = 3e5;
const ll bits = 20;
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll p = 29;

int main(){

    FASTIO;
    PRECISION; 
    
    int r,d,x;
    cin>>r>>d>>x;
    for(int i=0;i<10;i++){
        int nxt = r*x-d;
        cout<<nxt<<"\n";
        x = nxt;
    }
}
