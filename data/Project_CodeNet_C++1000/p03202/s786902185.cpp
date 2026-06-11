#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int A[200005];
int N;

bool boleh(int k){
    stack<ii> s1;
    //printf("boleh(%d)\n", k);

    stack<int> op;
    op.push(A[0]);
    int indx = 1;
    int val = 0;
    bool overflow = false;
    while(true){
        int target = op.top(); op.pop();
        int scenario = 0;
        //printf("%d\n", target);
        //printf("iteration indx=%d target=%d\n", indx, target);

        bool isTherePopping = false;
        while(!s1.empty()){
            ii temp = s1.top();
            if(temp.first > target){
                //printf("A: %d %d popped (1)\n", temp.first, temp.second);
                s1.pop();
                isTherePopping = true;
                //val = 1;
                continue;
            }else{
                break;
            }
        }

        int h = target;
        vector<int> toPush;
        bool taken = false;
        while(true){
            if(s1.empty()){
                //printf("%d %d pushed (empty stack)\n", h, h != target || isTherePopping);
                s1.push(ii(h, h != target || isTherePopping));
                reverse(toPush.begin(), toPush.end());
                for(int x: toPush){
                    //printf("%d %d pushed (3)\n", x, 0);
                    if(x < 1){return false;}
                    s1.push(ii(x, 0));
                }
                break;
            }
            ii temp = s1.top();

            taken = true;
            //printf("temp=ii(%d, %d)\n", temp.first, temp.second);
            if(temp.first<1 || h < 1){return false;}
            if(temp.first == h){
                s1.pop();
                //printf("ii(%d, %d) popped\n", temp.first, temp.second);
                if(temp.second+1 < k){
                    //printf("%d %d pushed (1)\n", temp.first, temp.second+1);
                    s1.push(ii(temp.first, temp.second+1));
                    scenario = 1;
                    reverse(toPush.begin(), toPush.end());
                    for(int x: toPush){
                        //printf("%d %d pushed (6)\n", x, 0);
                        if(x < 1){return false;}
                        s1.push(ii(x, 0));
                    }
                    break;
                }else{
                    toPush.push_back(temp.first);

                    h --;
                    if(h < 1){return 0;}
                }
            }else{
                //printf("%d %d pushed (4)\n", h, h != target || isTherePopping);
                s1.push(ii(h, h != target || isTherePopping));
                reverse(toPush.begin(), toPush.end());
                for(int x: toPush){
                    //printf("%d %d pushed (5)\n", x, 0);
                    if(x < 1){return false;}
                    s1.push(ii(x, 0));
                }
                break;
            }
        }


        /*reverse(toPush.begin(), toPush.end());
        for(int x: toPush){
            printf("%d %d pushed (3)\n", x, 1);
            s1.push(ii(x, 1));
        }*/

        //printf("indx=%d %d\n", indx, A[indx]);

        if(scenario != 2){
            if(op.empty()){
                val = 0;
                if(indx == N){break;}
                op.push(A[indx ++]);
                overflow = false;
            }
        }else{
            //printf("scenario=2; skipping this step\n");
        }
    }

    return true;
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &A[i]);
    }
    bool ansIs1 = true;
    for(int i = 1; i < N; i ++){
        if(A[i-1] >= A[i]){
            ansIs1 = false;
            break;
        }
    }
    if(ansIs1){
        printf("1");
        return 0;
    }

    int lo = 2;
    int hi = N;
    while(lo < hi){
        int mid = (lo+hi)>>1;
        if(boleh(mid)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    printf("%d", lo);
    return 0;
}
