// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<algorithm>
using namespace std;

long long machi[6];

int main()
{
    long long n;
    long long a[5];
    long long sum = 0;
    long long nokori;


    cin >> n;
   // cin >> a >> b >> c >> d >> e;

    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    //int key = 0;
    //while (key< 5) {
    //    if (n % a[key] == 0) {
    //        sum += n / a[key];
    //        if (key == 4)break;
    //        n = a[key] * (n / a[key] - 1) - a[key + 1] * (n / a[key ] - 1);
    //        if (n < 0)n = 0;
    //        n += a[key];
    //    }
    //    else {
    //        sum += n / a[key] + 1;
    //        long long amari = n % a[key];
    //        if (key == 4)break;
    //        n= a[key] * (n / a[key]) - a[key + 1] * (n / a[key ]);
    //        if (n < 0)n = 0;
    //        n +=amari;
    //    }

    //   // cout << sum << endl;
    //    key++;
    //}

    cout << max(max(max((n-1) / a[0]+1, (n-1) / a[1]+1),max(( n-1) / a[2]+1, (n-1) / a[3]+1)), (n-1) / a[4]+1)+4 << endl;



    return 0;


}
