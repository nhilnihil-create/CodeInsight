#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for(int i=0;i<N;i++){
        cin >> a.at(i);
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int pa=0,pb=0;

    for(int i=0;i<N;i++){
        if((i+1)%2==1){
            pa += a.at(i);
        }
        else{
            pb += a.at(i);
        }
    }

    cout << pa-pb << endl;
}