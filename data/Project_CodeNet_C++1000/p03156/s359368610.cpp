#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N, A ,B;
    cin >> N >> A >> B;

    int count_a = 0;
    int count_b = 0;
    int count_c = 0;

    for (int i = 0; i < N; i++){
        int P;
        cin >> P;
        if(P <= A){
            count_a++;
        }
        else if(A + 1 <= P && P <= B){
            count_b++;
        }
        else {
            count_c++;
        }
    }

    cout << min(count_a, min(count_b, count_c)) << endl;
}