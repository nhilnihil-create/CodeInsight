#include<iostream>
using namespace std;

main(){
    int n, a, b;
    cin >> n >> a >> b;
    int total = 0;
    int calc = 0;
    for (int x = 1;x <= n;x++){
        calc = 0;
        int y = x;
        while (y > 0){
            calc += y % 10;
            y = y / 10;
        }
        if (calc >= a && calc <= b) total += x;
    }

    cout << total << endl;
    return 0;

}