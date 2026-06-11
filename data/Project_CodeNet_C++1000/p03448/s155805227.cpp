#include <iostream>

int main()
{
    int A, B, C, X;
    std::cin >> A >> B >> C >> X;

    // 500 A
    // 100 B
    //  50 C

    int cnt = 0;

    for(int a=0; a<(A+1); a++)
    {
        for(int b=0; b<(B+1); b++)
        {
            for(int c=0; c<(C+1); c++)
            {
                if(500*a + 100*b + 50*c == X)
                    cnt++;
            }
        }
    }

    std::cout << cnt << std::endl;

}