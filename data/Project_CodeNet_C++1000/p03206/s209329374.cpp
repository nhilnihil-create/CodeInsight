#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) 0
#endif // LOCAL

int main(){
    int D;

    cin >> D;
    D = 25 - D;
    cout << "Christmas";
    for (int i = 0; i < D; i++) {
        cout << " Eve";
    }
    cout << '\n';
    
    return 0;
}