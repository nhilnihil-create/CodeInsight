#include <bits/stdc++.h>

using namespace std;


void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int first = max(max(a,b),c);
    int second =0;
    if(a== first){
         second = max(b,c);
    }
    else if(b == first){
         second = max(a,c);
    }
    else{
         second = max(b,a);
    }
    int last = min(min(a, b), c);
    first *= 10;
    first += second;
    first += last;
    cout << first << endl;

}

int main()
{
    solve();
    return 0;
}
