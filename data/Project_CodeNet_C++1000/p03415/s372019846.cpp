#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int A,B,C,D, K, N, H, W;
    long long int new_A, new_B, new_C, new_K;
    long long int a, b, c, d, e, f, g, h, i, j, k, l, m, n, s, w;
    vector<long long int> a_v;

    // int cnt = 0;
    // int now = 1;
    string str1, str2, str3;
    cin >> str1;
    cin >> str2;
    cin >> str3;
    cout << str1[0] << str2[1] << str3[2] << endl;
    // while(1) {
    //     if (now >= B) break;
    //     now -= 1;
    //     now += A;cnt++;
    // }
    // cout << cnt << endl;
    // cin >> H;
    // cin >> W;
    // string str[H];
    // long long int board[H][W] = {{0}};
    // // long long int res[H][W] = {{0}};
    // long long int sum = 0;

    // for (long long int i = 0; i < H; i++) {
    //     cin >> str[i];
    // } 

    // int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    // int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // for (long long int i = 0; i < H; i++) {
    //     for (long long int j = 0; j < W; j++) {
    //         board[i][j] = 0;
    //         if (str[i][j] == '#') {
    //             continue;
    //         }
    //         for (int k = 0; k < 8; k++) {
    //             long long int xx = j + dx[k];
    //             long long int yy = i + dy[k];
    //             if (0 <= xx && xx < W &&
    //                 0 <= yy && yy < H) {
    //                 if (str[yy][xx] == '#') {
    //                     board[i][j]++;
    //                 }
    //             }
    //         }
    //         // cout << board[i][j];
    //     }
    //                 // cout << endl;

    // }
    // for (long long int i = 0; i < H; i++) {
    //     for (long long int j = 0; j < W; j++) {
    //         if (str[i][j] == '#') {cout << "#";}
    //         else {
    //             cout << board[i][j];
    //         } 
    //     }
    //         cout << endl;
    // }
    // cout << str << endl;
    // long long int board[str.length()+1];
    // for (int i = 1; i <= str.length(); i++) {
    //     if (str[i] == '<') {
    //         board[i] = 1;
    //     } else {
    //         board[i] = 0;
    //     }
    // }
    // long long int sum = 0, cny = 0;
    // for (int i = 0; i < str.length(); i++) {
    //     if (board[i] == 1) {
    //         sum += i-cny;
    //         cny++;
    //     }
    // }
    // cout << sum << endl;
    // for (int i = 0; i < N; i++) {
    //     long long int a;
    //     cin >> a;
    //     a_v.push_back(a);
    // }

    // int now = 1;
    // bool flag = false;
    // for (i = 0; i < N; i++) { 
    //     now = a_v[now-1];
    //     // cout << now << endl;
    //     if (now == 2) {
    //         flag = true;
    //         break;
    //     }
    // }

    // if (flag) {
    //     cout << i+1 << endl;
    // }
    // else {
    //     cout << "-1" << endl;
    // }

    // cin >> A;
    // cin >> B;
    // cin >> C;
    // cin >> D;

    // while(1) {
    //     C = C-B;
    //     if (C <= 0) {break;} 
    //     A = A - D;    
    //     if (A <= 0) {break;} 
    // }
    // if (A <= 0) {
    //     cout << "No" << endl;
    // }
    // else {
    //     cout << "Yes" << endl;
    // }
    // long long int tmp, cnt = 0;
    // tmp = b;
    // for (;;) {
    //     tmp = tmp/10;
    //     cnt ++;
    //     if (tmp > 0) {
    //     }
    //     else {
    //         break;
    //     }
    // } 
    // long long int time = 1;
    // for (int i = 0; i < cnt; i++) {
    //     time *= 10;
    // }
    // b += a*time;
    // // cout << b<< endl;
    // bool flag = false;
    // for (long long int i = 0; i < sqrt(b)+1; i++) {
    //     if (i*i == b) {
    //         flag = true;
    //     }
    // }
    // if (flag) {
    //     cout << "Yes" << endl;
    // }
    // else {
    //     cout << "No" << endl;
    // }

    return 0;
}