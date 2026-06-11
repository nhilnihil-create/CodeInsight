#include <iostream>
#include <vector>

int main()
{
    int M, N, C;
    std::cin >> N >> M >> C;
    std::vector<std::vector<int>> A(N, std::vector<int> (M));
    std::vector<int> B(M);

    for(int i=0; i<M; i++)  std::cin >> B[i];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin >> A[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++)
    {
        long long sum = 0;
        for(int j=0; j<M; j++)
        {
            sum += A[i][j] * B[j];
        }

//        printf("***%d\n", sum);
        if( sum+C > 0 )
        {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}