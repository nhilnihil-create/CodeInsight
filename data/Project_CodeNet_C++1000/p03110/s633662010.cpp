#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
 
int main() {
    int N; 
    cin >> N;
    vector<double> gaku(N);
    vector<string> taipu(N);
    double otosidama=0.0;
    for(int i=0; i<N; i++){
        cin >> gaku.at(i);
        cin >> taipu.at(i);
        if(taipu.at(i) == "JPY"){
            otosidama += gaku.at(i);
        }
        else{
            otosidama += gaku.at(i) * 380000.0;
        }
    }
    cout << fixed <<setprecision(8) << otosidama << endl;
}