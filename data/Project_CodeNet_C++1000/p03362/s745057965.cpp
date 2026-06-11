#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin>>n;
    vector<int>list={11,31,41,71,101,131,151,181,191,211,241,251,271,281,311,331,401,421,431,461,491,521,541,571,601,631,641,661,691,701,751,761,811,821,881,911,941,971,991,1021,1031,1051,1061,1091,1151,1171,1181,1201,1231,1291,1301,1321,1381,1451,1471,1481,1511,1531,1571,1601};
    rep(i,n)cout<<list[i]<<" ";
    
	return 0;
}
