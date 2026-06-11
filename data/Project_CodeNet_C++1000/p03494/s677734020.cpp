#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    int A[N];
    for(int i=0; i<N; i++)
        std::cin >> A[i]; // A_iを代入

    int cnt=0;  // これは答え
    int cnt_i=0;
    while(true) // Aの全要素が2で割り切れる限り繰り返す
    {
        cnt_i=0; // この while ループの中で，A の全要素が2で割り切れるか判定する．0 なら割り切れる．
        for(int i=0; i<N; i++) // 各要素が2で割り切れるか検証する．
        {
            if(A[i]%2 != 0) // 割り切れないときは
                cnt_i++; // cnt_i を 0 以外にする
            else
                A[i]/=2; // 次のループのために2で割る
        }

        if(cnt_i == 0) // 全要素が2で割り切れるとき
            cnt++; // 答えの cnt に1加える
        else
            break; // 2 で割り切れない要素があれば抜ける．
    }

    std::cout << cnt << std::endl;
    
}