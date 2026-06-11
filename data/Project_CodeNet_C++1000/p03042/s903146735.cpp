#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int s;
    cin >> s;
    int y=s/100;
    int m=s-y*100;

    if(0<y && y<=12 && 0<m && m<=12){
        cout << "AMBIGUOUS" << endl;
    }else if(0<y && y<=12 && (m>12 || m==0)){
        cout << "MMYY" << endl;
    }else if((y==0 || y>12) && 0<m && m<=12){
        cout << "YYMM" << endl;
    }else{
        cout << "NA" << endl;

    }
}