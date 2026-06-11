#include<cstdio>
const static int MAX_H = 50;
const static int MAX_W = 50;
bool is_black[MAX_H+2][MAX_W+2];
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};

int main(){
    unsigned H, W;
    scanf("%u %u", &H, &W);
    for (size_t i = 1; i <= H; i++){
        scanf("\n");
        for (size_t j = 1; j <= W; j++){
            char s;
            scanf("%c", &s);
            is_black[i][j] = s == '#';
        }
    }
    bool isolated;
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            if(!is_black[i][j]) continue;
            isolated = true;
            for (size_t k = 0; k < 4; k++){
                if(is_black[i + x[k]][j + y[k]]){
                    isolated = false;
                    break;
                }
            }
            if(isolated){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
	return 0;
}