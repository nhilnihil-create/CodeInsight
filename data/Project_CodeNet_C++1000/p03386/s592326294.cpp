#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int a,b,k;
    cin >> a >> b >> k;
    set<int> st;
    for (int i = 0;i < k;i++){
        if (i+a <= b) st.insert(i+a);
    }
    for (int i = 0;i < k;i++){
        if (b+i-k+1 >= a) st.insert(b+i-k+1);
    }
    for (auto q:st){
        cout << q << endl;
    }

   return 0;

}