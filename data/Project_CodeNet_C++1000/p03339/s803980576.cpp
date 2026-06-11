#include <iostream>
// #include <algorithm>
// #include <functional>
using namespace std;

// int main(){
//     int n;
//     string s;
//     cin >> n;
//     cin >> s;

//     int sum_1 = 0;
//     for (int i = 1; i < n; i++){
//         if (s[i] == 'E') sum_1 ++;
//     }

//     int currentmin = sum_1;

//     for (int i = 1; i < n; i++){
//         if(s[i - 1] == 'W') sum_1 ++;
//         if(s[i] == 'E') sum_1 --;
//         if (sum_1 < currentmin) currentmin = sum_1;
//     }
 
//     cout << currentmin << endl;
//     return 0;
// }

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    //累積和
    // int sum[n];
    // for (int i = 0; i < n; i++) sum[i] = 0;

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j <= i; j++){
    //         if(s[j] == 'W') sum[i] += 1;
    //     }
    // }

    int counter = 0;
    int sum[n];
    for (int i = 0; i < n; i++) sum[i] = 0;

    for (int i = 0; i < n; i++){
        if (s[i] == 'W') counter ++;
        sum[i] = counter;
        // cout << sum[i] << endl;
    }

    int currentmin = 0;
    // int counter = 0;
    counter = 0;

    for (int i = 0; i < n; i++){
        if (i == 0) {
            counter = n - sum[n-1];
            currentmin = counter;
        }else{
            counter = sum[i - 1] + ( ( n - ( i + 1 )) - (sum[n-1] - sum[i]) );
            if (counter < currentmin) currentmin = counter;
        }
        // cout << counter << currentmin << endl;
    }
    cout << currentmin << endl;
    
    return 0;
}