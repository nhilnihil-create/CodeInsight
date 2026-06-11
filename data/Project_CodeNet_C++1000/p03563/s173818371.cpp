#include <bits/stdc++.h>
using namespace std;

int main(){
    int nowRating,wantsRating;
    cin >> nowRating >> wantsRating;

    int targetRating = (wantsRating * 2) - nowRating;
    cout << targetRating << endl;
}