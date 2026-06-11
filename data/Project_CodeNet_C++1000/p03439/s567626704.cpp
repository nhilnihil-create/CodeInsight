#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

map<string, int> m={{"Vacant",0}, {"Male",1}, {"Female",-1}};

bool bin_search(int l, int r, int state){
    int mid=(l+r)/2;

    cout << mid << endl;
    string s;
    cin >> s;

    if(m[s]==0){
        return true;
    }else if((mid%2==0 && m[s]==state) || (mid%2==1 && m[s]==-state)){
        return bin_search(mid, r, state);
    }else{
        return bin_search(l, mid, state);
    }

}

int main(){
    int N;
    cin >> N;

    cout << 0 << endl;
    string s;
    cin >> s;
    if(m[s]==0)return 0;
    bin_search(1, N, m[s]);
}
