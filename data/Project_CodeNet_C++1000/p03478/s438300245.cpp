#include <iostream>

int main()
{
    int N, A, B;
    std::cin >> N >> A >> B;

    int cnt=0;

    for(int i=0; i<N+1; i++)
    {
        int fig_sum = i/10000 + (i-(i/10000)*10000)/1000 + (i-(i/1000)*1000)/100 + (i-(i/100)*100)/10 + (i-(i/10)*10);

        if(A <= fig_sum && fig_sum <= B)
            cnt+=i;
    }

    std::cout << cnt << std::endl;
}