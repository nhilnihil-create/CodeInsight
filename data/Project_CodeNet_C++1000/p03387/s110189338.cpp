#include<cstdio>

using namespace std;

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);

    int max = A;
    if(max < B) max = B;
    if(max < C) max = C;
    int sum = A + B + C;
    if(sum % 2 != max % 2) {
        ++max;
    }
    printf("%d\n", ((max * 3) - sum)/2);
    return 0;
}
