#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<functional>
#include<bitset>
using namespace std;
typedef	long long int ll;

int main(){
    int l;
    cin >> l;
    vector<int> v;
    bitset<20> bit(l);
    for(int i=0; i<20; i++){
        if(bit[i]==1){
            v.push_back(i);
        }
    }
    int n = v[v.size()-1]+1;
    int m = 2*(n-1)+v.size()-1;
    cout << n << ' ' << m << endl;
    for(int i = 1; i < n; i++){
        cout << i << ' ' << i+1 << ' ' << pow(2, n-i-1) << endl;
        cout << i << ' ' << i+1 << ' ' << 0 << endl;
    }
    int total = pow(2, n-1);
    for(int i = 0; i < v.size()-1; i++){
        cout << 1 << ' ' << n-v[i] << ' ' << total << endl;
        total += pow(2, v[i]);
    }
    return 0;
}