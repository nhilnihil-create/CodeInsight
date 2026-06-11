#include <iostream>

using namespace std;

int main()
{
    long long N, M;
    long long card;


    cin >> N >> M;

    if( N == 1 && M == 1 ) //どちらも1なら裏
        card = 1;
    else if( N == 1 || M == 1 ) //どちらかが1なら端の2枚以外裏
        card = N*M - 2;
//    else if( N == 2 || M == 2 ) //どちらかが2なら裏のカードはない
//        card = 0;
    else //周囲は必ず表、中は必ず裏
        card = (N-2)*(M-2);

    cout << card << endl;

    return 0;
}