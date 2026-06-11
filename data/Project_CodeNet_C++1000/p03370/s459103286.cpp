#include <iostream>

int main ()
{
    int N, X;
    std::cin >> N >> X;

    int m[N];
    int m_min = 1000;
    int m_sum = 0;
    for(int i=0; i<N; i++)
    {
        std::cin >> m[i];
        m_min = std::min(m_min, m[i]); // 一番省エネなドーナツの m
        m_sum += m[i]; // N種類を1個ずつ作るときに消費する m の合計
    }

    int X_rest = X - m_sum; // 省エネなドーナツを量産するための粉の m ． 
    int num = X_rest / m_min; // 省エネなドーナツを作れる余分な個数．

    std::cout << N+num << std::endl;
}