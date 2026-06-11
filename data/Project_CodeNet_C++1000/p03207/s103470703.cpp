#include <iostream>

using namespace std;

int main () {
   int N;
        cin >> N;
        int P=0;
        int X=0;
        for(int i=0;i<N;i++){
            int M; cin>>M;
            P=max(M,P);
            X+=M;
        }
        cout << X-(P/2);

    // enter your code here

    return 0;
}
