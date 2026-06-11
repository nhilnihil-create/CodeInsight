#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int collatz(int x){
    if(x % 2 == 0){
        return x / 2;
    }
    else{
        return x * 3 + 1;
    }
}
int main(void){
    int s;
    cin >> s;
    vector<int> a;
    map<int,int> b;
    a.push_back(s);
    b[s]++;
    int ans = 0;
    for(int i=1;;i++){
        a.push_back(collatz(a[i-1]));
        if(b[a[i]]){
            ans = i + 1;
            break;
        }
        else{
            b[a[i]]++;
        }
    }
    
    
    cout << ans << endl;
}
