#include<iostream>

int main(){
int r,c;
 std::cin >> r >> c;
 char a[r][c];
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        std::cin >> a[i][j];
    }
 }
 char count;
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        count='0';
        if(a[i][j]=='#') continue;

        if(a[i+1][j]=='#' && i+1>=0 && i+1<=r-1) count++;
        if(a[i-1][j]=='#' && i-1>=0 && i-1<=r-1) count++;

        if(a[i][j+1]=='#' && j+1>=0 && j+1<=c-1) count++;
        if(a[i][j-1]=='#' && j-1>=0 && j-1<=c-1) count++;

        if(a[i-1][j+1]=='#' && (j+1>=0 && j+1<=c-1) && (i-1>=0 && i-1<=r-1)) count++;
        if(a[i+1][j-1]=='#' && (j-1>=0 && j-1<=c-1) && (i+1>=0 && i+1<=r-1)) count++;

        if(a[i-1][j-1]=='#' && (j-1>=0 && j-1<=c-1) && (i-1>=0 && i-1<=r-1)) count++;
        if(a[i+1][j+1]=='#' && (j+1>=0 && j+1<=c-1) && (i+1>=0 && i+1<=r-1)) count++;

        a[i][j]=count;
    }
 }

 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        std::cout <<a[i][j];
    }
    std::cout << "\n";
 }
 return 0;
}
