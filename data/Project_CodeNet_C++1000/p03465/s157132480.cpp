#include <bits/stdc++.h>
using namespace std;

int A[2005];

bitset<4000005> possible;

int main(){
    int N;
    scanf("%d", &N);

    int sum = 0;
    for(int i = 0; i < N; i ++){
        scanf("%d", &A[i]);
        sum += A[i];
    }
    int halfSum = (sum+1)/ 2;

    possible[0] = 1;
    for(int i = 0; i < N; i ++){
        possible |= (possible << A[i]);
    }

    /*for(int i = 0; i <= sum; i ++){
        printf("%d", (int)possible[i]);
    }
    printf("\n");*/

    int ans3 = 0;
    for(int i = halfSum; i <= sum; i ++){
        if(possible[i]){
            printf("%d", i);
            ans3 = i;
            break;
            //return 0;
        }
    }

    return 0;
    printf("\nAns: %d\n", ans3);

    vector<int> ans;
    for(int i = 0; i < (1<<N); i ++){
        int temp = 0;
        for(int j = 0; j < N; j ++){
            if(i&(1<<j)){
                temp += A[j];
            }
        }
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());
    /*for(int i: ans){
        printf("%d ", i);
    }
    printf("\n");*/
    printf("Correct ans: %d\n", ans[1<<(N-1)]);
    printf("%d %d %d\n", ans[(1<<(N-1))-1], ans[(1<<(N-1))], ans[(1<<(N-1))+1]);
    printf("HalfSum: %d\n", ans[(1<<N)-1]/2);
    return 0;
}
