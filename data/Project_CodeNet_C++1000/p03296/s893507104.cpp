#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    int count=0;
    for(int i=0;i<N;i++) cin >> a.at(i);
    for(int i=0;i<N-1;i++){
        if(a.at(i)==a.at(i+1)){
            a.at(i+1)=0;
            count++;
        }
    }
    cout << count << endl;
}
