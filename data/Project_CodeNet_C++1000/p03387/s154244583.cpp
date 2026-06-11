#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int A[3];
    scanf("%d %d %d", A, A+1, A+2);
    int lowest = min({A[0], A[1], A[2]}), highest = max({A[0], A[1], A[2]});
    unsigned candidate, answer = 78;
    for (int goal = lowest; goal <= highest + 1; goal++){
        candidate = 0;
        for (size_t i = 0; i < 3; i++){
            if(A[i] >= goal) candidate += A[i] - goal;
            else{
                candidate += goal - A[i] >> 1;
                if(goal - A[i] & 1) candidate += 2;
            }
        }
        if(candidate < answer) answer = candidate;
    }
    printf("%u\n", answer);
	return 0;
}