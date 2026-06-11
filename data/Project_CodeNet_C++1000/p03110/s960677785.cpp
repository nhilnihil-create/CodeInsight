#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    double sumbit=0;
    double sumyen=0;

    for(int i=0; i<N; i++){
        double x;
        string u;
        cin >> x >> u;

        if(u == "JPY"){
            sumyen += x;
        }else{
            sumbit += x;
        }
    }

    sumyen += sumbit*380000;

    cout << sumyen << endl;
    return 0;
}